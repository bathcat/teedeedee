# Lab: RESTful Fortune

## Summary
A major shortcoming of the standard [fortune](https://en.wikipedia.org/wiki/Fortune_(Unix))
application is it's near total lack facts about dogs and/or numbers.

For example, `fortune` will never tell you this--
> The smallest known adult dog was a Yorkshire Terrier that was only 2.5 inches 
> at the shoulder, and weighed only 4  ounces.

Or this--
> 20000000000 is the approximate number of coconuts produced worldwide each year.


To remedy the situation, build a command-line application
that gets its fortune data from a public web API.  

Here are 2 public APIs:
* http://numbersapi.com/random/trivia?json
* http://dog-api.kinduff.com/api/facts

<br/>

## Goals
* Leverage external libraries
  - Use whatever you want, but the 2 below are already included as dependencies via bazel.
* Wrap libraries for testability
* Write deterministic tests

<br/>

## Requirements
* Make an HTTP request using the header-based library [`cpp-httplib`](https://github.com/yhirose/cpp-httplib).
* Extract the meaningful content using [`nlohmann/json`](https://github.com/nlohmann/json).
* Display on the terminal
