<template>
  <v-container>
    <v-row class="text-center">
      <v-col cols="12">
        <IOTcomponent />
      </v-col>
    </v-row>
  </v-container>
</template>

<script>
import IOTcomponent from "../views/IOTcomponent.vue";
export default {
  name: "HelloWorld",
  components: {
    IOTcomponent
  },
  data() {
    return {};
  },
};
</script>
