

#include <ansi.h>
void test_me(object me);
inherit ROOM;

void create()
{
        set("short",  HIR "����" NOR );
        set("long",HIR @LONG
�����񻰼��Σ��ܵ�����������һ����������ͷʹ�Ľ�ɫ��
����һ��������˵�ͷ�Ͳ�ʹ�ˣ����ͷӦ�ÿ�ʼʹ�˰ɣ�����
LONG
      NOR);
        

        set("no_pk", 1);
        set("no_move", 1);
        setup();
}
void init()
{
              if(!wizardp(this_player())) 
        {
        "/cmds/std/look"->look_room(this_player(),this_object());
        this_player()->set("startroom", __FILE__);
        add_action("do_nothing", "");
        add_action("do_quit","quit");
        }
}

int block_cmd()
{
        string verb = query_verb();
        
        if (verb=="say") return 0; //allow say
        if (verb=="help") return 0;
        if (verb=="look") return 0;
        return 1;
}


int do_nothing()
{
        string verb = query_verb();
        if (verb=="say") return 0; //allow say
        if (verb=="eat") return 0; //allow eat
        if (verb=="help") return 0;
        if (verb=="look") return 0;
// 50          if (verb=="exert") return 0;
write("�������廨����أ���������\n");
return 1;
}

int do_quit()
{
"/cmds/eld/quit"->main(this_player(),"");
return 1;
}
