# Week8-HomeWorks
See the two homeworks in the respective directories
## What is Neyman Construction?
[This](https://en.wikipedia.org/wiki/Neyman_construction) is a method to constuct an interval at a confidence level in such a way that it generates true valus within that interval for (many) repeated experiments. 
## Minimum of a Function.
I have used the [Golden Section Search](https://en.wikipedia.org/wiki/Golden-section_search) to find the minimum of the the function. 
## How to Run the Programs?
I have been using [ C++](https://learn.microsoft.com/en-us/cpp/build/vscpp-step-0-installation?view=msvc-170) and [ROOT](https://root.cern/install/) to develop these programs. In case you are missing the it in your system, you can [install](https://root.cern/install/). We can run these programs using [ROOT] *macro* by simply put these commands in your [ROOT](https://root.cern/install/) terminal. Pass an integer(```number of experiments```) as an argument of the function or type root[0] **`.x NeymanConst.C(20000)`** .  
For the hw9 the macro can be run as in the main terminal as **`root FunctionMin.C`** or in the root terminal as root[0] **`.x FunctionMin.C`** . This program will print the minimum of the function. 
