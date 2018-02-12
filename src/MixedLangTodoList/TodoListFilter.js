import React, { Component } from "react";

class TodoListFilter extends Component {
  render () {
    const {onUpdate} = this.props;
    return (
      <input
        type="text"
        placeholder="search"
        onChange={e => onUpdate(e.target.value)}
      />
    );
  }
};
// can't be use atm (https://github.com/BuckleScript/bucklescript/issues/2067)
// export default TodoListFilter

module.exports = TodoListFilter;
