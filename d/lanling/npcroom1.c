// ���� by Calvin

inherit ROOM;
void create ()
{
        set ("short", "���ĸ�");
        set ("long", @LONG

���ߵ����������������д���˴ӹ���������������ߺ���,
���������������µ�ǧ�Ŵ��������ع���,�������Ϸ�ȴ��һ��
                     ��������������������������
�������,����д��:   ����  ��  ��  ��  ��  ���� �ĸ����֡�
                     ��������������������������

LONG);

        set("exits", 
        ([ //sizeof() == 4
          "west" : "/d/calvin/lanling/npcroom" ,
          "east" : "/d/calvin/lanling/npcroom2" ,
        ]));

        set("objects", 
        ([ //sizeof() == 1
//        "/d/calvin/obj/score.c" : 1,
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
