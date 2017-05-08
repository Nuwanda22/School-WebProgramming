import React, { Component } from 'react';
// import logo from '../logo.svg';
import '../App.css';
import { Player } from '../components';
import Axios from 'axios';
import Sound from 'react-sound';

class App extends Component {
  constructor() {
    super();
    this.clinetId = 'd483a639c26987060fabcd74a0b10763';
    this.state = {
      track: {
        stream_url: '',
        artwork_url: ''
      },
      tracks: [],
      playStatus: Sound.status.PLAYING
    };

    this.loadPlaylist = this.loadPlaylist.bind(this);
    this.randomSong = this.randomSong.bind(this);
    this.stop = this.stop.bind(this);
  }

  stop() {
    if (this.state.playStatus === Sound.status.PLAYING) {
      this.setState({
        playStatus: Sound.status.PAUSED
      });
    } else {
      this.setState({
        playStatus: Sound.status.PLAYING
      });
    }
  }

  loadPlaylist() {
    Axios.get(`https://api.soundcloud.com/playlists/317926079?client_id=` + this.clinetId).then((res) => {
      console.log("1111 " + res.toString());
      const trackLength = res.data.tracks.length;
      const randomSong = Math.floor((Math.random() * trackLength) + 1);
      this.setState({
        track: res.data.tracks[randomSong],
        tracks: res.data.tracks
      });
    }).catch((err) => {
      console.log(err);
    });
  }

  randomSong() {
    const trackLength = this.state.tracks.length;
    const randomSong = Math.floor((Math.random() * trackLength) + 1);
    this.setState({
      track: this.state.tracks[randomSong]
    });
  }

  addClientId(url) {
    return `${url}?client_id=${this.clinetId}`;
  }

  componentDidMount() {
    this.loadPlaylist();
  }

  render() {
    return (
      <div className="App">
        <Sound url={this.addClientId(this.state.track.stream_url)} 
          playStatus={this.state.playStatus}
          onFinishedPlaying={this.randomSong} />
        <Player prev={this.randomSong} next={this.randomSong} stop={this.stop}/>
      </div>
    );
  }
}

export default App;
