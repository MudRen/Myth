
//shangu2.c Ѱˮ����
inherit ROOM;
void create()
{
        set("short", "ɽ��");
        set("long", @LONG
�������ʻ���������·������ڻ��ĺ���Զ���ĺ���������ˡ�
LONG
        );
   set("exits", ([
      "north" : __DIR__"shangu",
      "southwest" : __DIR__"shuitan",
      "southeast" : __DIR__"xiaolu",
      "west" : __DIR__"xiaowu",
   ]));
   setup();
   replace_program(ROOM);
}
