<template>
  <v-card>
    <v-toolbar color="cyan" dark flat>
      <template v-slot:extension>
        <v-tabs v-model="tabs" centered slider-color="yellow">
          <v-tab :key="1"> Temperature </v-tab>
          <v-tab :key="2"> Switch </v-tab>
        </v-tabs>
      </template>
    </v-toolbar>
    <v-tabs-items v-model="tabs">
      <v-tab-item>
        <temparature />
      </v-tab-item>
      <v-tab-item>
        <switchComponent/>
      </v-tab-item>
    </v-tabs-items>
  </v-card>
</template>

<script>
import temparature from './temperature.vue'
import switchComponent from './Switchcomponent.vue'

export default {
  name: "IOTcomponent",
  data() {
    return {
      tabs: "",
    };
  },
  components: {
      temparature,
      switchComponent
  }
};
</script>
