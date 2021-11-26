<template>
  <v-row justify="center">
    <v-col cols="6" v-if="devices.length">
      <v-row justify="center" v-for="(item, index) in devices" :key="index">
        <v-col cols="6" align="center" class="mt-5">
          <p>MAC_ID: {{ item }}</p>
        </v-col>
        <v-col cols="2">
          <v-switch
            v-model="switch1"
            @change="toggle(item)"
            color="success"
            class="pl-8"
          ></v-switch>
        </v-col>
        <v-col cols="4">
          <v-btn
            class="ma-1 mt-3"
            color="error"
            @click="remove(item)"
          >
            Delete
          </v-btn>
        </v-col>
      </v-row>
    </v-col>
    <!-- <v-sheet
      :max-width="model === 6 ? 128 : 256"
      class="mx-auto transition-swing secondary circle"
      elevation="12"
      height="128"
      width="100%"
    ></v-sheet> -->
  </v-row>
</template>

<script>
const axios = require("axios");

export default {
  name: "switchComponent",
  data() {
    return {
      DeviceName: "",
      switch1: false,
      mac: "",
      body: {
        MAC_ID: 1,
      },
      devices: [],
    };
  },
  mounted() {
    axios
      .get("http://localhost:8080/api/connectedDevices")
      .then((data) => {
        console.log(data, "received data");
        this.devices = data.data.devices;
        console.log(this.devices);
      });
  },
  methods: {
    toggle(deviceName) {
      console.log(deviceName, "DeviceName");
      axios
        .post("http://localhost:8080/api/sendMessage", {
          macId: this.devices[0],
          state: this.switch1 ? 1 : 0,
        })
        .then((data) => {
          console.log(data, "received data");
        });
    },
    remove(macid) {
      axios.post("http://localhost:8080/api/deleteDevice", {
        macid 
      }).then((response) => {
        console.log(response, "After delete");
      })
      axios
      .get("http://localhost:8080/api/connectedDevices")
      .then((data) => {
        console.log(data, "received data");
        this.devices = data.data.devices;
        console.log(this.devices);
      });
    }
  },
};
</script>
