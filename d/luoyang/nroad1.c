inherit ROOM;

void create()
{
        set("short", "����·");
        set("long", @LONG
������·�������������һ����·���ֵ������ɾ�������������·
�汻��ˮ��ù����羵����·������߷��ߴ����ΰ���������Ǿ޸�լԺ��
˫�˺ϱ�������ʮ��һ�꣬������������ߡ������Ƿ�Բ�����������˲�
֪�����˲���������¥��������ר�����������ʵ�������ר���ꡣ
LONG);
        set("outdoors", "luoyang");
        set("no_clean_up", 0);
        set("exits", ([
                "east" : __DIR__"zuixianlou",
                "north" : __DIR__"nroad2",
                "south" : __DIR__"center",
                "west" : __DIR__"tangsancai",
        ]));

        setup();
        replace_program(ROOM);
}

