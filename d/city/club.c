//Cracked by Roath
//changan city

inherit ROOM;

void create ()
{
        set ("short", "�����ַ�");
        set ("long", @LONG

�����ǳ�����һ�����������ֳ�������ҹĻ���ٺ�����͸������֡�
���������Ŀ����д�ٹ��ˣ��������������ã��˼����ĵ����ӣ���
���Ⱥ�ı�ʿ����ʱҲ�ܿ���һЩ���׿ʹ���ɮ�˻��ʿ��
   | | |          | | |        | | |         | | |
  �~�~�~�~ .    �~�~�~�~ .   �~�~�~�~      �~�~�~�~
���~�~�~�~��  ���~�~�~�~�� ���~�~�~�~��  ���~�~�~�~��
�~������֨~. �~ף����˨~ �~ףԸ��Ҩ~  �~�ϼһ��֨~
���~�~�~�~�� .���~�~�~�~�� ���~�~�~�~��  ���~�~�~�~��
  �~�~�~�~ .    �~�~�~�~ .   �~�~�~�~      �~�~�~�~
   | | |        | | | |      | | | |       | | | |

LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
                "up" : __DIR__"clubup",
                "east" : __DIR__"zhuque-s2",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                "d/gumu/npc/meiniang" : 1,
//                "/d/obj/misc/tables" : 1,
  //              "/d/obj/misc/chairs" : 2,
        ]));


//        set("outdoors", "changan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}


