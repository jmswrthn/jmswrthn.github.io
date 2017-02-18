<script>
    document.getElementById("linklist").onchange = function() {
    if (this.selectedIndex!==0) {
        window.location.href = this.value;
        this.selectedIndex=0;
    }
};
</script>
