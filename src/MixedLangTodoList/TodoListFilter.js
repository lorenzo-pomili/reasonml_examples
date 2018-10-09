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

export default TodoListFilter;
