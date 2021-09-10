#include <sys/stat.h>
#include <sys/param.h>
#include <sys/types.h>
#include <string.h>
#include <assert.h>
#include <errno.h>

/** Like mkdir, but creates all the directories leading up to path.
 * In the event of failure, returns a negative value (usually -1) and
 * errno is set as per mkdir(2).  If path is longer than MAXPATHLEN
 * then -2 is returned and errno is set to ENAMETOOLONG.  If a
 * component of the path exists and isn't a directory, -3 is returned
 * and errno is set to ENOTDIR.  A return of 0 means that path is
 * now an existing directory, though no gaurantee is made about whether
 * it's actually writable.
 */

int mkpath(const char* path, mode_t mode)
{
  char p[MAXPATHLEN];
  int c = 0, ret;
  char *lastslash = 0;
  struct stat s;

  if (!path || !*path) return 0;
  while (*path) {
    if (c >= MAXPATHLEN) {
      errno = ENAMETOOLONG;
      return -2;
    }
    p[c++] = *path++;
  }
  p[c] = 0;

  lastslash = strchr(p+1, '/');
  while (1) {
    if (lastslash) *lastslash = 0;
    ret = stat(p, &s);
    if (ret < 0) {
      ret = mkdir(p, mode);
      if (ret < 0) return ret;
    } else {
      if (!S_ISDIR(s.st_mode)) {
        errno = ENOTDIR;
        return -3;
      }
    }
    if (!lastslash) return 0;
    *lastslash = '/';
    lastslash = strchr(lastslash+1, '/');
  }
  assert("impossible state");
  return 0;
}

int main(int ac, char** av) {
  int ret = mkpath(av[1], 0777);
  printf("%s %d %s\n", av[1], ret, strerror(errno));
}
