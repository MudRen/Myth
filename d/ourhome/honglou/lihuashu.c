
inherit ROOM;
int number=1+random(4);
void create ()
{
  set ("short", "�滨����");
  set ("long", @LONG

     �滨Ժ�������£��������������硣

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"yard2",
]));
  setup();
}
void init() {
  add_action("do_dig",({"dig","wa","jue"}));
}

int do_dig(string arg) {

  object wan,me=this_player();

  if (!arg && arg!="tree" && arg!="lihua tree")
    return notify_fail("��Ҫ��ʲô��\n");
  
  if (me->is_busy()) return notify_fail("��Ϣһ������ڰɡ�\n");

  me->add("kee",-50);
  message_vision("$N���滨�������˰��죬�۵���ͷ�󺹡�\n",me);
  if (!random(5))
      if (!number)
         message_vision("$N�ڳ�һ��ϸ��ҩ̳��ȴ��������տ���Ҳ��\n",me);
      else {
         message_vision("$N�ڳ�һ��ϸ��ҩ̳���������ó���һ��ҩ�衣\n",me);
         wan=new("/d/obj/drug/lengxiangwan");
         if (!wan->move(me)) wan->move(this_object());
         number--;
      }
  me->start_busy(3+random(3));
  return 1;
}         
    
        
