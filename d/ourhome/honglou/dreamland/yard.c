
//�յ�.c Ѱˮ����
inherit ROOM;
void create()
{
        set("short", "�յ�");
        set("long", @LONG
һ��СС�Ŀյأ�һ��Ư����СŮ�����������档
LONG);
   set("exits", ([
      "west" : __DIR__"xiaolu",
   ]));
   set("objects", ([
   __DIR__"npc/girl" : 1,
   ]));
   setup();
   replace_program(ROOM);
}
