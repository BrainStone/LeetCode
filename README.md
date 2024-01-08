# LeetCode C++ Template

This little project is a template for running LeetCode problems locally in your CLion installation.

## Usage

- Install the [LeetCode Editor](https://plugins.jetbrains.com/plugin/12132-leetcode-editor) plugin
- Configure the plugin and log in to your account as you normally would
- Configure the `problems` folder as the `TempFilePath` of the plugin
- Copy the templates from the `templates` folder into the respective templates of the plugin
- Start solving problems and enjoy each problem being locally debuggable

### Caveats

Since C++20 doesn't have reflection

- Be sure to reload CMake after each new project
- Be sure to make the entry function look like this:
  ```c++
  class Solution {
  // ...
  public:
  	<return type> <function-name>(<argument-list>)
  // ...
  };
  ```
- Be sure to reload CMake after changing the entry function's parameter types (like for example by changing `string`
  to `const string&`)
