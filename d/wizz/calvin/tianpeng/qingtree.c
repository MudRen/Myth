// ���� by Calvin

inherit ROOM;
int number=1+random(4);
void create ()
{
  set ("short", "�黨��");
  set ("long", @LONG

     ��������Ϊ����,ֻ������������

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : "/d/calvin/tianpeng/pomiao",
]));
         set ("no_quit",1);
  setup();
}

void init() {
  add_action("do_dig",({"ku"}));
}

int do_dig(string arg) {
  object wan,me=this_player();
  if (!arg && arg!="tree" && arg!="qing tree")
    return notify_fail("��Ҫ��ʲô��\n");

  if (me->is_busy()) return notify_fail("��Ϣһ����ɡ�\n");

  me->add("kee",-10);
  message_vision("$N���黨������Ȼ�Ŀ��ˡ�\n",me);
  if (!random(5))
      if (!number)
         message_vision("$N���˰���,�۾������ˡ�\n",me);
      else {
         message_vision("�黨����$N�Ŀ����ж���,ͻȻ������һ����ʵ��\n",me);
         wan=new("/d/calvin/obj/yangshen");
         if (!wan->move(me)) wan->move(this_object());
         number--;
      }
  me->start_busy(2+random(1));
  return 1;
}         
