
//shangu.c Ѱˮ����
inherit ROOM;
void create()
{
        set("short", "ɽ��");
        set("long", @LONG
����һ�������ʻ���ɽ�ȣ��������Ǻ������۷䡣Զ���ƺ���������ˮ����
�����и��ٲ���
LONG);
   set("exits", ([
      "south" : __DIR__"shangu2",
      "north" : __DIR__"dreamland",
   ]));
   setup();
   replace_program(ROOM);
}
