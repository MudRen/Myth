
//С·.c Ѱˮ����
inherit ROOM;
void create()
{
        set("short", "С·");
        set("long", @LONG
һ��С·���������������ߡ�
LONG);
set("outdoors",1);
   set("exits", ([
      "northwest" : __DIR__"shangu2",
      "east" : __DIR__"yard",
   ]));
   setup();
   replace_program(ROOM);
}
