// created by angell 1/1/2001
// room: /d/qujing/huangfeng/jiangtang.c

inherit ROOM;

void create ()
{
  set ("short", "������");
  set ("long", @LONG

���ҽ��壬һ�����ϡ���ǰ���ϰ����ɹ��ɻ�����Ʒ���ȡ�
�Իͱ���������������ޣ�������㣬�������̷ɲ���
�����������������ж�������������

LONG);

  set("exits", ([
        "south"    : __DIR__"chanyuan",
	"north" : __DIR__"changjing",
      ]));

  set("objects", ([
      __DIR__"npc/lingjipusa": 1,       
          __DIR__"npc/daoren":2,
	]));
  setup();
}