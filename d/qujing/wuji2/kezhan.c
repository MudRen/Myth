// Room: /d/changan/kezhan  snowcat moved to /d/qujing/wuji
inherit ROOM;

int block_cmd(string);
void create ()
{
  set ("short", "��Ԫ��ջ");
  set ("long", @LONG

��ҿ�ջλ���ڼ����������Ԫ���жΣ���������ǳ���¡����
�������Ŀ��˶��ڴ�Ъ�š��������õ�С�������ػ��д����ķ���
�͡�¥���ǿͷ���

LONG);

  set("no_fight", 1);
  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/xiaoer" : 1,
  ]));
  set("resource", ([ /* sizeof() == 1 */
      "water" : 1,
    ]));
  set("exits", ([ /* sizeof() == 5 */
    "up" : __DIR__"up",
    "north" : __DIR__"estreet2",
  ]));
  set("no_magic", 1);
  set("valid_startroom", 1);
  setup();
}

void init()
{
}

int valid_leave(object me, string dir)
{
  object mbox;

  if ( !me->query_temp("rent_paid") && dir == "up" )
    return notify_fail("��С��������Ц�ص�ס���㣺�Բ��𣬿ͷ�������š�\n");

  return ::valid_leave(me, dir);
}


