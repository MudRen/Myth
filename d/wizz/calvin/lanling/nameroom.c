// ������ by Calvin

inherit ROOM;

void create ()
{
        set ("short", "��Ե����");
        set ("long", @LONG

����һ��ר������ɾ���������޸�ͷ�εĵ���,�����ڵ����ⳤ��ĺ�,
��˵�ϰ�ԭ���Ǿ��ǵ�һλ��������,��ǰ��ҵ��̵����ƾ���������
��������ġ�

LONG);

        set("exits", 
        ([ //sizeof() == 4
          "east": "/d/calvin/lanling/jie3",
        ]));

        set("objects", 
        ([ //sizeof() == 1
          "d/city/npc/qing" : 1,
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
