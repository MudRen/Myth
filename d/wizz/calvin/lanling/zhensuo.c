// ������ by Calvin

inherit ROOM;

void create ()
{
        set ("short", "�ش�����");
        set ("long", @LONG

����һ�Ҹ߼�������,�������ϰ�Ҳ��������������������,�ϰ�����ٻ�����,��
С�ͱ����˸�����ҽ�鼮,���ں�����ʱ�������Լ�������,�����Լ��Ķ���֮����
����һ���СëС�����������Ļ��¡������ʹ��(cure)����ҽ�Ρ�

LONG);

        set("exits", 
        ([ //sizeof() == 4
          "east": "/d/calvin/lanling/jie2",
        ]));

        set("objects", 
        ([ //sizeof() == 1
          "/d/calvin/npc/yishi" : 1,
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
