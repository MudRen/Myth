inherit ROOM;

void create()
{
        set("short", "��ٵ�");
        set("long", @LONG
����һ��������ֱ����������Ĵ�ٵ�������ݵ���ʮ���ۡ�����
ͨ�򺯹ȹؿ��Դ����ݳǣ���������Ե��ﶫ�������ųǡ�
LONG);
        set("outdoors", "luoyang");
        set("no_clean_up", 0);
        set("exits", ([
                "west" : __DIR__"guandaoe3",
                "east" : "/d/changan/hanguguan",
        ]));

        setup();
        replace_program(ROOM);
}

