inherit ROOM;

void create()
{
        set("short", "�����");
        set("long", @LONG
��������������ͷ���Щ�����Ͽ�ʱ�����������ĺ��ӵģ������ֺ�
��С�����Һ����ȣ�û���κζ���������վ�Ų��ܰ��κ����ƣ������ӵ�
�������ܷ���С���ӿ�Ҫ�úóԳԿ�ͷ�ˡ�
LONG);
        set("no_clean_up", 0);
        set("exits", ([
                "south" : __DIR__"sishu",
        ]));
        set("objects", ([
                "/d/gao/npc/kid" : 1,
        ]));
        setup();
        replace_program(ROOM);
}

