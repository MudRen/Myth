
inherit ROOM;
int xianguan_block();

void create ()
{
  set ("short", "���ض���");
  set ("long", @LONG

���ض���һ�����������ſ������������ɾơ���������˱ǣ�
�м�����Ƶ��ɹ٣��������ʿ���켸����ˮ�ĵ��ˣ��ջ��
ͯ�ӣ��ڴ�������Һ�����������𡣽�������������(door)
ͨ�����Ƶĵؽѡ�

LONG);

  set("exits", ([
        "west"  : "/d/pantao/yaob",
        "south"  : __DIR__"gate",
//      "down" :__DIR__"jiujiao",
      ]));

  set("xianguan",1);
   set("objects",([
    __DIR__"npc/xianguan" :1,
  ]));

  setup();
}

void init() {
  add_action("to_open","open");
}

int to_open(string arg) {
  object me=this_player();

  if (!arg || arg!="door") return notify_fail("��ʲô��\n");
  if(query("exits/down")) return notify_fail("���Ѿ��ǿ��ŵ��ˡ�\n");

  if (xianguan_block()) 
    return notify_fail("����ɹٿ�����һ�ۣ����ŵ����ϰ����ȥ���ŵ������˻�����\n");

  if (me->query("force")<200) {
    message_vision("$Nʹ��ȫ���������ţ�����������ݺ���������˿��δ����\n",me);
    return notify_fail("�������������\n");
  }
  message_vision("$N��һ����������һ�ƣ�����������Ϣ�Ĵ��ˡ�\n",me);
  add("exits",(["down":__DIR__"jiujiao",]));
  me->start_busy(2);
  me->set_temp("yaochi_open",1);
  call_out("door_close",10);
  return 1;
}
void door_close() {

  remove_call_out("door_close");
  tell_room(this_object(),"����������Ϣ�Ĺ����ˡ�\n");
  set("exits", ([
        "west"  : "/d/pantao/yaob",
        "south"  : __DIR__"gate",
      ]));
}

int valid_leave(object me, string dir)
{
    if ( dir == "down" && xianguan_block()) 
      return notify_fail("����ɹ����������ǰ���������أ���\n");
    return ::valid_leave(me, dir);
}

int xianguan_block() {
  object xianguan=present("zaojiu xianguan",this_object());

  if (xianguan && living(xianguan)) return 1;
  return 0;
}

