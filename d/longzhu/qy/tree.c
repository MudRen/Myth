// ��Ҷ���� by Calvin

inherit ROOM;
int number=1+random(4);
void create ()
{
  set ("short", "��Ҷ����");
  set ("long", @LONG

     ��Ҷ������Ҳ�飬���������鲻�顣

LONG);

  set("exits", ([ /* sizeof() == 1 */
   "west" : "/d/milin/qy/sc7",
]));

        set("objects", 
        ([ //sizeof() == 1
        "/d/quest/longzhu/npc/xiaolin" : 1, 
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

  me->add("kee",-200);
  message_vision("$N����Ҷ�������˰��죬�۵���ͷ�󺹡�\n",me);
  if (!random(5))
      if (!number)
         message_vision("$N�ڳ�һ������̽����,����ȴ���Ĳ��������ˡ�\n",me);
      else {
         message_vision("$N�ڳ�һ�������ޱȵı���,���ó��Ǳ������顣\n",me);
        wan=new("/d/quest/longzhu/obj/2");
         if (!wan->move(me)) wan->move(this_object());
         number--;
      }
  me->start_busy(5+random(5));
  return 1;
}         

