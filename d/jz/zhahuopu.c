//Cracked by Roath

inherit ROOM;
void create()
{
        set("short", "�ӻ���");
        set("long", @LONG

    ���ǽ���Ψһ��һ���ӻ��̣����������߰���Ķ���һЩ��Ʒ��
�����ϰ�Ҳ��һ������������ӡ�����������������ϵ����˴���
�к���
LONG );
        set("exits", ([
                "north" : __DIR__"pingan-1",
        ]));
        set("objects", ([
    __DIR__"npc/yang":1,
        ]));
      setup();
        replace_program(ROOM);
}
