const binding = require("bindings")("windowtoolboxbinding");
delete binding.path;
module.exports = binding;
