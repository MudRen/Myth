// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/jiuguan.c

inherit ROOM;

void create ()
{
  set ("short", "�ƹ�");
  set ("long", @LONG

С�ƹ���߾ƹ����ظߡ�������Կ���������Ƹס�ǽ�Ϲ���һ
Щ�ƺ�«�ƴ��������Ϸ��Ŵ�����ţ�⡣�Ʊ�һ���д����ˣ�
һ��������ţ�⡣

LONG);

  set("exits", ([
        "east"         : __DIR__"caichang",
      ]));

  set("objects", ([
         __DIR__"npc/jiubao" : 1,
      ]));

  setup();
}

