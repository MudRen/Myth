inherit BULLETIN_BOARD;
#include <ansi.h>

void create()
{
        set_name(HIR"�����ʾ��"NOR, ({ "board" }) );
        set("location", "/d/lanling/�������");
       set("board_id", "lanling1_b");
        set("long",
                "����һ�������,��ר��Ϊ��Щϲ����������ī�ʵ����ṩ��.�����(post)��\n" );
        setup();
        set("capacity", 200);
        replace_program(BULLETIN_BOARD);
}
