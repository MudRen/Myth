// Room: /u/rainy/sea/yidao.c
inherit ROOM;

void create ()
{
  set ("short", "�ǵ�");
  set ("long", @LONG

�����ǻ�԰�е�һ��С��������Χ�����β����Ǿ�����������·�ϡ�����
����ϸС�İ�ɫʯ�ӣ��ߴ��в�ľ��ӳ��������ǵ�ͨ�����ܣ��򡡡���
���ͻص��˺�����

LONG);

  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"jiashan2.c",
  "north" : __DIR__"jiashan1.c",
  "west" : __DIR__"inside4",
  "east" : __DIR__"shiwu.c",
]));
//      
        set("water", 1);
//  
  setup();
}
