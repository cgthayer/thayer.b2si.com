# Hackweek

Goals

Hackathons are for experimenting and learning so we are gearing this to be any level of experience. Some parts are ambitious, but folks are welcome to play with what's comfortable for them, and can be involved in just a few days of the hackweek.

* Big Hairy Goal: Make bringing up a test nomad datacenter ("zone") easily reproducible by any engineer.
* Learn about running Consul in-depth
* Learn about Consul federation (and nomad and vault)
* Discover any issues for Roblox code related to federation
* Document how to create a datacenter-like workbench
* Big Hairy Goal: Repo the conditions of the Halloween Incident in a simple workbench environment, and learn a ton.
* Rough Plan

A few of us will be in the channel and zoom available all week to help unblock anyone and help debugging.

Day 1 (Mon 12/13): Learn the basics using docker compose

Morning: check out Rob Cameron's consul federation demo and runs through the steps (video)
Afternoon: continue but with consul, vault, (nomad?) using the Hashicorp Jupyter notebook
Hashicorp: a timeframe (about 3hr, 1-4pm PST) where there's zoom availability (Zoom)

Day 2 Tue: Try on real hardware

Morning: Add nomad to the jupyter work.
Afternoon: Repeat bringing up a hashistack but using 6-12 AWS compute nodes (terraform?)
Hashicorp: 11am zoom checkin for 30min to answer questions
Hashicorp: slack channel #roblox-collab-hashi-enablement 

Day 3 Wed: Federate Consul

Morning: Adjust to have different peoples clusters talking to each other 
Afternoon: Run simple services that talk across clusters
Hashicorp: slack channel

Day 4 Thu: Run Roblox services

Morning: Bring up Traefik
Afternoon: Bring up MVP of infra-services like Obelix (runtime config), ...
Try some Roblox platform services (see also Operator's Manual for Provisioning a new BEDEV environment
Can we get to Part 2: Platform, Stage 1: Telemetry, Databases? (there are 5 stages)
Hashicorp: slack channel

Day 5 Fri: Presentation

For the group itself. Share issues, pros, and cons of experience.
Rob Cameron might make a video if we get to something demonstrable.
Alternative tracks

You may wish to only participate in some parts or take a different focus, so here are some options:

Local-dev: Do the steps but limited to docker-compose.
k8s: Consul works in k8s, so use that instead of nomad if you're more comfortable with it
Bringup: Focus on bringing up our Platform stack, document ordering and dependencies.
Telemetry: Include a telemetry stack in the mini-datacenter (dashboards, logging, or tracing)
Consul-only: Skip the nomad/k8s parts and use docker-compose to run your services by hand

