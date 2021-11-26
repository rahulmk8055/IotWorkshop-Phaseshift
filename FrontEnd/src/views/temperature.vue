<template>
  <div>
    <!-- <v-card flat>
      <v-card-text class="text-h5 mb-1"> Temperature is {{ temp }}</v-card-text>
      <v-card-text class="text-h5 mb-1">
        Humidity is {{ humidity }}</v-card-text
      >
    </v-card> -->
    <v-card class="mx-auto" max-width="400">
      <v-list-item two-line>
        <v-list-item-content>
          <v-list-item-title class="text-h5"> Bengaluru </v-list-item-title>
          <v-list-item-subtitle
            >{{ date }}</v-list-item-subtitle
          >
        </v-list-item-content>
      </v-list-item>

      <v-card-text>
        <v-row align="center">
          <v-col class="text-h2" cols="6"> {{ temp }}&deg;C </v-col>
          <v-col cols="6">
            <v-img
              src="https://cdn.vuetifyjs.com/images/cards/sun.png"
              alt="Sunny image"
              width="92"
            ></v-img>
          </v-col>
        </v-row>
        <v-row>
          <v-col class="text-h2" cols="6"> {{ humidity }}AH </v-col>
          <v-col class="text-h4" cols="6">
            <v-row class='mt-4'>
              Humidity
            </v-row>
          </v-col>
        </v-row>
      </v-card-text>

      <v-list-item>
        <v-list-item-icon>
          <v-icon>mdi-send</v-icon>
        </v-list-item-icon>
        <v-list-item-subtitle>23 km/h</v-list-item-subtitle>
      </v-list-item>

      <v-list-item>
        <v-list-item-icon>
          <v-icon>mdi-cloud-download</v-icon>
        </v-list-item-icon>
        <v-list-item-subtitle>48%</v-list-item-subtitle>
      </v-list-item>
    </v-card>
  </div>
</template>

<script>
const axios = require("axios");

export default {
  name: "temperature",
  data() {
    return {
      temp: "",
      humidity: "",
      time: 0,
      interval: undefined,
      date: "",
    };
  },
  mounted() {
    this.getWeather();
  },
  methods: {
    async getWeather() {
      this.interval = setInterval(() => {
        axios
          .get("http://localhost:8080/api/sensor", {
            headers: {
              "Access-Control-Allow-Origin": "*",
              "Access-Control-Allow-Methods":
                "GET, POST, PATCH, PUT, DELETE, OPTIONS",
              "Access-Control-Allow-Headers":
                "Origin, Content-Type, X-Auth-Token",
            },
          })
          .then((data) => {
            this.temp = data.data.temperature;
            this.humidity = data.data.humidity;
          });
        const d = new Date();
        this.date = d.toDateString();
        console.log(this.date, "Date");
      }, 2500);
    },
  },
};
</script>
