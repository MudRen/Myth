// Room: ��Щ���ܻ�û���ϣ����������ֵô��� by koker2001/04/29
// siyuan.c

inherit ROOM;

void create ()
{
  set ("short", "˼Դ��");
  set ("long", @LONG

���������Ƕ���˼Դ�ã���С��ʦ�����������˼Դ�ĵط���
����ĳ���Ҳʮ�ֵļ򵥣��������Ķ������Ҳ�������ʯ��
��ǽ�Ϻ������һЩ�֣��㲻��ϸ�������ܿ�����
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"jingtang.c",
 
]));
  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/xiao" : 1,
  __DIR__"npc/yunyang" : 1,
]));
  set("valid_startroom", 1);

  setup();
}


