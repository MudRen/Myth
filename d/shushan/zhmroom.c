//Cracked by Roath
//����ɽ���ɡ�dhxy-evil 2000.7.5
inherit ROOM;

void create()
{
        set("short", "��Ϣ��");
        set("long", @LONG
        ���Ǽ�������᷿�����Ŵ������ţ����ߺܻ谵������������
ֻ���м����һ����ʰ����������Ĵ󴲣����ž�������˯����
LONG
        );
        set("exits", ([
                "southwest" : __DIR__"dadian",
        ]));

        set("sleep_room", 1);
        set("no_fight", 1);

        setup();
}

