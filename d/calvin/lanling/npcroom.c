//����

inherit ROOM;
void create ()
{
        set ("short", "�����");
        set ("long", @LONG

���ߵ����������������д���˴ӹ������������Ӣ�ۺ���,
���������������µ�ǧ�Ŵ��������ع���,�ٿ������Ϸ���һ��
                     ��������������������������
�������,����д��:   ����  ��  Ȼ  ��  ��  ���� �ĸ����֡�
                     ��������������������������

LONG);

        set("exits", 
             ([ //sizeof() == 4
             "west" : "/d/calvin/lanling/jie5",   
          "east" : "/d/calvin/lanling/npcroom1",
        ]));

        set("objects", 
        ([ //sizeof() == 1
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
