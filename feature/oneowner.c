// oneowner.c
// the function check_owner() should be put in init() of a given object.
// it will ensure that only the first user who get this 
// object can keep it, otherwise it will disappear automatically.

// mon 2/7/98

private static string obj_owner=0;
nomask void self_destroy();

void check_owner()
{
  object env=environment();

  if(!clonep()) return;

  if(!env) {
    call_out("self_destroy",1);
    return;
  }
    
  //for room or other containers.  
  if(!env->is_character()) {
    if(obj_owner) call_out("self_destroy",5+random(5));
    return;
  }  
  
  //for npc.
  if(!userp(env)) {
    if(obj_owner)
      call_out("self_destroy",5+random(5));
    return; 
    //allow NPC to carry it if no one has own it.
  }  
     
  //following is for user.   
  if(!obj_owner)
    obj_owner=env->query("id");
  else {
    if(obj_owner!=env->query("id"))
      call_out("self_destroy",2+random(5));
    else
      remove_call_out("self_destroy");  
      //one can still pick it up if loses it for a short while.
  }
}

void self_destroy()
{
  object env=environment();

  if(env) {
    if(env->is_character()) { // npc or player
      tell_object(env,"���Ϻ�Ȼ����һ���Ϻȣ�����"+
        this_object()->query("name")+"����\n");
      tell_object(env,"ֻ��"+this_object()->query("name")
        +"��ն�ȥ����ʱ�䲻������Ӱ��\n");  
    } else {
      tell_object(env,this_object()->query("name")+
        "��������ʱ�䲻������Ӱ��\n");
    }
  }
  
  destruct(this_object());
}
