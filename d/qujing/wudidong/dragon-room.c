// created by mes, updated 6-17-97 pickle

inherit ROOM;
void create ()
{
  set ("short", "��Ѩ");
  set ("long", @LONG

����ʯ��һ�ƣ��ԹԲ����ˡ�����ԭ�����������ĳ�Ѩ����Ȼ����û
��ˮ������ʪ�ޱȡ��Ĵ����Ÿ��ָ������δ�����ĳ��ӣ�������һ
�Ѻ���(bones)��ɢ�����󸯳�֮����
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"well",
]));
  set("outdoors", 0);
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/dragon" : 1,
]));

  setup();
}

void init()
{
	add_action("do_move", "move");
}

int valid_leave(object me, string dir)
{
  if(dir=="west" &&
     objectp(present("dragon", environment(me))))
    return notify_fail("������ס�����ȥ·��\n");
  return ::valid_leave(me, dir);
}

int clean_up()
{
  return 0;
}

int do_move()
{
	object me=this_player();
	object biyaoshi;

	if( !(biyaoshi =find_object(__DIR__"biyaoshi"))) 
		biyaoshi=load_object(__DIR__"biyaoshi");
	if( biyaoshi = find_object(__DIR__"biyaoshi")) {
		message_vision("$N�ƶ��˼������ǣ���Ȼ������һ����ť��\n", me);
		if(biyaoshi->query("door_locked")) {
			message_vision("$N���˰���ť��ȴʲôҲû������\n", me);
		}
		else {
			message_vision("$N����һ�°�ť������ͻȻ����һ���ѷ죬\n", me);
			message_vision("$N�����ѷ�֮���ѷ�ͺ����ˡ�\n", me);
			me->move(__DIR__"biyaoshi");
		}
	}
	return 1;
}

