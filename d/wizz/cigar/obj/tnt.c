#include <ansi.h>
inherit ITEM;
void create()
{
        set_name( HIY "TNTը��" NOR , ({ "tnt"}) );
        set("long", "����һ������ʮ���ը����ר������ը(zha)�����е���ʦ���Ρ�\n");
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 0);
              }
        setup();
}

void init()
{
 add_action("do_zha","zha");
}

int do_zha(string arg)
{
string old_status, new_status;
int my_level, ob_level, level;
 object ob,me=this_player();
 if(!arg) return notify_fail("����ը˭��\n");
 if( wiz_level(me) < wiz_level(new_status) ) return notify_fail("��Ȼը����˾���볭���㰡��\n");
 if(!ob=find_player(arg)) return notify_fail("����ը˭��\n");
//  if( !wizardp(ob) ) return notify_fail("��ֻ��ը��ʦŶ��\n");
//  if( !ob->query("env/invisibility") ) return notify_fail("�ѵ��㿴������\n");

 message_vision(HIR"$Nȡ��һ��TNTը����������һ�ף�TNTը�������۾��Ƶģ���Զ����ȥ...\n��һ�����Զ������һ�����졣\n" NOR,  me );
 message("vision", HIR"��Ȼһ��TNTը����Х����"+ob->name()+"����������,���һ���죬"+ob->name()+"��ը����ԭ�Ρ�\n"NOR,  environment(ob), ({ ob }) );

tell_object(ob,HIR "��Ȼһ��TNTը��ײ�������ϣ���ը�ˣ��Ƶ����ֳ���ԭ�Ρ�\nԭ����"+me->name()+"���㶪TNTը��:->��\n" NOR);
 ob->set("env/invisibility",0);
 destruct(this_object());
 return 1;
}
