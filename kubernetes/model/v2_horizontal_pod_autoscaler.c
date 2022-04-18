#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v2_horizontal_pod_autoscaler.h"



v2_horizontal_pod_autoscaler_t *v2_horizontal_pod_autoscaler_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v2_horizontal_pod_autoscaler_spec_t *spec,
    v2_horizontal_pod_autoscaler_status_t *status
    ) {
    v2_horizontal_pod_autoscaler_t *v2_horizontal_pod_autoscaler_local_var = malloc(sizeof(v2_horizontal_pod_autoscaler_t));
    if (!v2_horizontal_pod_autoscaler_local_var) {
        return NULL;
    }
    v2_horizontal_pod_autoscaler_local_var->api_version = api_version;
    v2_horizontal_pod_autoscaler_local_var->kind = kind;
    v2_horizontal_pod_autoscaler_local_var->metadata = metadata;
    v2_horizontal_pod_autoscaler_local_var->spec = spec;
    v2_horizontal_pod_autoscaler_local_var->status = status;

    return v2_horizontal_pod_autoscaler_local_var;
}


void v2_horizontal_pod_autoscaler_free(v2_horizontal_pod_autoscaler_t *v2_horizontal_pod_autoscaler) {
    if(NULL == v2_horizontal_pod_autoscaler){
        return ;
    }
    listEntry_t *listEntry;
    if (v2_horizontal_pod_autoscaler->api_version) {
        free(v2_horizontal_pod_autoscaler->api_version);
        v2_horizontal_pod_autoscaler->api_version = NULL;
    }
    if (v2_horizontal_pod_autoscaler->kind) {
        free(v2_horizontal_pod_autoscaler->kind);
        v2_horizontal_pod_autoscaler->kind = NULL;
    }
    if (v2_horizontal_pod_autoscaler->metadata) {
        v1_object_meta_free(v2_horizontal_pod_autoscaler->metadata);
        v2_horizontal_pod_autoscaler->metadata = NULL;
    }
    if (v2_horizontal_pod_autoscaler->spec) {
        v2_horizontal_pod_autoscaler_spec_free(v2_horizontal_pod_autoscaler->spec);
        v2_horizontal_pod_autoscaler->spec = NULL;
    }
    if (v2_horizontal_pod_autoscaler->status) {
        v2_horizontal_pod_autoscaler_status_free(v2_horizontal_pod_autoscaler->status);
        v2_horizontal_pod_autoscaler->status = NULL;
    }
    free(v2_horizontal_pod_autoscaler);
}

cJSON *v2_horizontal_pod_autoscaler_convertToJSON(v2_horizontal_pod_autoscaler_t *v2_horizontal_pod_autoscaler) {
    cJSON *item = cJSON_CreateObject();

    // v2_horizontal_pod_autoscaler->api_version
    if(v2_horizontal_pod_autoscaler->api_version) {
    if(cJSON_AddStringToObject(item, "apiVersion", v2_horizontal_pod_autoscaler->api_version) == NULL) {
    goto fail; //String
    }
    }


    // v2_horizontal_pod_autoscaler->kind
    if(v2_horizontal_pod_autoscaler->kind) {
    if(cJSON_AddStringToObject(item, "kind", v2_horizontal_pod_autoscaler->kind) == NULL) {
    goto fail; //String
    }
    }


    // v2_horizontal_pod_autoscaler->metadata
    if(v2_horizontal_pod_autoscaler->metadata) {
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v2_horizontal_pod_autoscaler->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v2_horizontal_pod_autoscaler->spec
    if(v2_horizontal_pod_autoscaler->spec) {
    cJSON *spec_local_JSON = v2_horizontal_pod_autoscaler_spec_convertToJSON(v2_horizontal_pod_autoscaler->spec);
    if(spec_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "spec", spec_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v2_horizontal_pod_autoscaler->status
    if(v2_horizontal_pod_autoscaler->status) {
    cJSON *status_local_JSON = v2_horizontal_pod_autoscaler_status_convertToJSON(v2_horizontal_pod_autoscaler->status);
    if(status_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "status", status_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v2_horizontal_pod_autoscaler_t *v2_horizontal_pod_autoscaler_parseFromJSON(cJSON *v2_horizontal_pod_autoscalerJSON){

    v2_horizontal_pod_autoscaler_t *v2_horizontal_pod_autoscaler_local_var = NULL;

    // define the local variable for v2_horizontal_pod_autoscaler->metadata
    v1_object_meta_t *metadata_local_nonprim = NULL;

    // define the local variable for v2_horizontal_pod_autoscaler->spec
    v2_horizontal_pod_autoscaler_spec_t *spec_local_nonprim = NULL;

    // define the local variable for v2_horizontal_pod_autoscaler->status
    v2_horizontal_pod_autoscaler_status_t *status_local_nonprim = NULL;

    // v2_horizontal_pod_autoscaler->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(v2_horizontal_pod_autoscalerJSON, "apiVersion");
    if (api_version) { 
    if(!cJSON_IsString(api_version))
    {
    goto end; //String
    }
    }

    // v2_horizontal_pod_autoscaler->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v2_horizontal_pod_autoscalerJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }
    }

    // v2_horizontal_pod_autoscaler->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v2_horizontal_pod_autoscalerJSON, "metadata");
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v2_horizontal_pod_autoscaler->spec
    cJSON *spec = cJSON_GetObjectItemCaseSensitive(v2_horizontal_pod_autoscalerJSON, "spec");
    if (spec) { 
    spec_local_nonprim = v2_horizontal_pod_autoscaler_spec_parseFromJSON(spec); //nonprimitive
    }

    // v2_horizontal_pod_autoscaler->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(v2_horizontal_pod_autoscalerJSON, "status");
    if (status) { 
    status_local_nonprim = v2_horizontal_pod_autoscaler_status_parseFromJSON(status); //nonprimitive
    }


    v2_horizontal_pod_autoscaler_local_var = v2_horizontal_pod_autoscaler_create (
        api_version ? strdup(api_version->valuestring) : NULL,
        kind ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        spec ? spec_local_nonprim : NULL,
        status ? status_local_nonprim : NULL
        );

    return v2_horizontal_pod_autoscaler_local_var;
end:
    if (metadata_local_nonprim) {
        v1_object_meta_free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    if (spec_local_nonprim) {
        v2_horizontal_pod_autoscaler_spec_free(spec_local_nonprim);
        spec_local_nonprim = NULL;
    }
    if (status_local_nonprim) {
        v2_horizontal_pod_autoscaler_status_free(status_local_nonprim);
        status_local_nonprim = NULL;
    }
    return NULL;

}
