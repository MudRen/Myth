inherit ROOM;

void falldown(object,object);

void init() {
    object me=this_player();
    call_out("falldown",5+random(10),me,this_object());
}

void falldown(object me,object env) {
    string dest;
    
    if (env!=environment(me)) return;
    message_vision("$N����һ����������ˤ����ȥ��\n",me);
    dest=env->query("exits/down");
    if (!dest) return;
    me->move(dest);
    tell_room(environment(me),"һ�����죬"+me->query("name")+
          "���������ˤ�˸�����ſ��\n",me);
   me->set_busy(3+random(3));
}
