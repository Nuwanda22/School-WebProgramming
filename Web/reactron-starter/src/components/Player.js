import React, { Component } from 'react';

const playerStyle = {
  display: 'flex'
}

const playerButtonStyle = {
  display: 'flex',
  justifyContent: 'center',
  color: 'black',
  fontSize: '10rem',
  cursor: 'pointer'
}

class Player extends Component {
  render() {
    return (
      <div style={playerStyle}>
        <div onClick={this.props.prev} style={playerButtonStyle}>{"<"}</div>
        <div onClick={this.props.stop} style={playerButtonStyle}>{"o"}</div>
        <div onClick={this.props.next} style={playerButtonStyle}>{">"}</div>
      </div>
    );
  }
}

export default Player;
