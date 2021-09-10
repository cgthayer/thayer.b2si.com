# -*- coding: utf-8 -*-
"""
    MoinMoin technical theme

    @copyright: (c) 2003-2004 by Nir Soffer
    @license: GNU GPL, see COPYING for details.

    As modified by Heather Stern for Ubuntu
"""

from MoinMoin.theme import modern


class Theme(modern.Theme):

    name = "indie"

        
def execute(request):
    """ Generate and return a theme object
        
    @param request: the request object
    @rtype: Theme instance
    @return: Theme object
    """
    return Theme(request)

