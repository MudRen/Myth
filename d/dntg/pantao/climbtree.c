void init() {
   add_action("do_climb","climb");
}

int do_climb(string arg)
{
  object *bulb;
  object me=this_player();
  string dest;
 
  if( (!arg) || arg != "tree" )
    return notify_fail("��ʲô��\n");
  if( me->query("kee") < (int)(me->query("max_kee")/3)){
    me->receive_damage("kee",(int)me->query("kee")/2);
    return notify_fail("�����ӷ��飬һͷ������������ѽ��\n");
  }

  bulb=all_inventory();
  for (int i=0;i<sizeof(bulb);i++) 
     if (living(bulb[i]) && bulb[i]!=me)
        return notify_fail("���ű��˵�������͵�ң����ײ��ס�\n");
  dest=__DIR__+(string)this_object()->query("up");
  tell_object(me,"�㱿�ֱ��ŵ�������ȥ��\n");
  me->move(dest);
  tell_room(environment(me),me->query("name")+"���ֱ��ŵ�����������",me);
  return 1;
}
