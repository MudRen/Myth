// rewritten by snowcat.c 4/4/1997
// room: /d/nuerguo/maowu.c

inherit ROOM;

void create ()
{
  set ("short", "é��");
  set ("long", @LONG

����һ���ª��Сé�ݡ��ı���«�˴�ɡ�����ֻ��һЩ��
���������þߡ�һλ���������Ŷ����������俴�����ǰڶ�
�ϸ��˵Ľ�㡣
LONG);

  set("exits", ([ 
        "south" : __DIR__"westriver",
      ]));

  set("objects",([
        __DIR__"npc/oldwoman" : 1,
       ]));

  setup();
}






