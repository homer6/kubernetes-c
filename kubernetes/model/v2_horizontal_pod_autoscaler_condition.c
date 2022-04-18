#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v2_horizontal_pod_autoscaler_condition.h"



v2_horizontal_pod_autoscaler_condition_t *v2_horizontal_pod_autoscaler_condition_create(
    char *last_transition_time,
    char *message,
    char *reason,
    char *status,
    char *type
    ) {
    v2_horizontal_pod_autoscaler_condition_t *v2_horizontal_pod_autoscaler_condition_local_var = malloc(sizeof(v2_horizontal_pod_autoscaler_condition_t));
    if (!v2_horizontal_pod_autoscaler_condition_local_var) {
        return NULL;
    }
    v2_horizontal_pod_autoscaler_condition_local_var->last_transition_time = last_transition_time;
    v2_horizontal_pod_autoscaler_condition_local_var->message = message;
    v2_horizontal_pod_autoscaler_condition_local_var->reason = reason;
    v2_horizontal_pod_autoscaler_condition_local_var->status = status;
    v2_horizontal_pod_autoscaler_condition_local_var->type = type;

    return v2_horizontal_pod_autoscaler_condition_local_var;
}


void v2_horizontal_pod_autoscaler_condition_free(v2_horizontal_pod_autoscaler_condition_t *v2_horizontal_pod_autoscaler_condition) {
    if(NULL == v2_horizontal_pod_autoscaler_condition){
        return ;
    }
    listEntry_t *listEntry;
    if (v2_horizontal_pod_autoscaler_condition->last_transition_time) {
        free(v2_horizontal_pod_autoscaler_condition->last_transition_time);
        v2_horizontal_pod_autoscaler_condition->last_transition_time = NULL;
    }
    if (v2_horizontal_pod_autoscaler_condition->message) {
        free(v2_horizontal_pod_autoscaler_condition->message);
        v2_horizontal_pod_autoscaler_condition->message = NULL;
    }
    if (v2_horizontal_pod_autoscaler_condition->reason) {
        free(v2_horizontal_pod_autoscaler_condition->reason);
        v2_horizontal_pod_autoscaler_condition->reason = NULL;
    }
    if (v2_horizontal_pod_autoscaler_condition->status) {
        free(v2_horizontal_pod_autoscaler_condition->status);
        v2_horizontal_pod_autoscaler_condition->status = NULL;
    }
    if (v2_horizontal_pod_autoscaler_condition->type) {
        free(v2_horizontal_pod_autoscaler_condition->type);
        v2_horizontal_pod_autoscaler_condition->type = NULL;
    }
    free(v2_horizontal_pod_autoscaler_condition);
}

cJSON *v2_horizontal_pod_autoscaler_condition_convertToJSON(v2_horizontal_pod_autoscaler_condition_t *v2_horizontal_pod_autoscaler_condition) {
    cJSON *item = cJSON_CreateObject();

    // v2_horizontal_pod_autoscaler_condition->last_transition_time
    if(v2_horizontal_pod_autoscaler_condition->last_transition_time) {
    if(cJSON_AddStringToObject(item, "lastTransitionTime", v2_horizontal_pod_autoscaler_condition->last_transition_time) == NULL) {
    goto fail; //Date-Time
    }
    }


    // v2_horizontal_pod_autoscaler_condition->message
    if(v2_horizontal_pod_autoscaler_condition->message) {
    if(cJSON_AddStringToObject(item, "message", v2_horizontal_pod_autoscaler_condition->message) == NULL) {
    goto fail; //String
    }
    }


    // v2_horizontal_pod_autoscaler_condition->reason
    if(v2_horizontal_pod_autoscaler_condition->reason) {
    if(cJSON_AddStringToObject(item, "reason", v2_horizontal_pod_autoscaler_condition->reason) == NULL) {
    goto fail; //String
    }
    }


    // v2_horizontal_pod_autoscaler_condition->status
    if (!v2_horizontal_pod_autoscaler_condition->status) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "status", v2_horizontal_pod_autoscaler_condition->status) == NULL) {
    goto fail; //String
    }


    // v2_horizontal_pod_autoscaler_condition->type
    if (!v2_horizontal_pod_autoscaler_condition->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", v2_horizontal_pod_autoscaler_condition->type) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v2_horizontal_pod_autoscaler_condition_t *v2_horizontal_pod_autoscaler_condition_parseFromJSON(cJSON *v2_horizontal_pod_autoscaler_conditionJSON){

    v2_horizontal_pod_autoscaler_condition_t *v2_horizontal_pod_autoscaler_condition_local_var = NULL;

    // v2_horizontal_pod_autoscaler_condition->last_transition_time
    cJSON *last_transition_time = cJSON_GetObjectItemCaseSensitive(v2_horizontal_pod_autoscaler_conditionJSON, "lastTransitionTime");
    if (last_transition_time) { 
    if(!cJSON_IsString(last_transition_time))
    {
    goto end; //DateTime
    }
    }

    // v2_horizontal_pod_autoscaler_condition->message
    cJSON *message = cJSON_GetObjectItemCaseSensitive(v2_horizontal_pod_autoscaler_conditionJSON, "message");
    if (message) { 
    if(!cJSON_IsString(message))
    {
    goto end; //String
    }
    }

    // v2_horizontal_pod_autoscaler_condition->reason
    cJSON *reason = cJSON_GetObjectItemCaseSensitive(v2_horizontal_pod_autoscaler_conditionJSON, "reason");
    if (reason) { 
    if(!cJSON_IsString(reason))
    {
    goto end; //String
    }
    }

    // v2_horizontal_pod_autoscaler_condition->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(v2_horizontal_pod_autoscaler_conditionJSON, "status");
    if (!status) {
        goto end;
    }

    
    if(!cJSON_IsString(status))
    {
    goto end; //String
    }

    // v2_horizontal_pod_autoscaler_condition->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(v2_horizontal_pod_autoscaler_conditionJSON, "type");
    if (!type) {
        goto end;
    }

    
    if(!cJSON_IsString(type))
    {
    goto end; //String
    }


    v2_horizontal_pod_autoscaler_condition_local_var = v2_horizontal_pod_autoscaler_condition_create (
        last_transition_time ? strdup(last_transition_time->valuestring) : NULL,
        message ? strdup(message->valuestring) : NULL,
        reason ? strdup(reason->valuestring) : NULL,
        strdup(status->valuestring),
        strdup(type->valuestring)
        );

    return v2_horizontal_pod_autoscaler_condition_local_var;
end:
    return NULL;

}
