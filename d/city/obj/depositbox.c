//box.c

inherit ITEM;

void create()
{
    set_name("����",({"deposit box","box"}));
    set_weight(1000);
    set_max_encumbrance(10000);
    if( clonep() )
         set_default_object(__FILE__);
    else
     {
         set("unit", "ֻ");
         set("long", "����һֻ�����Ĵ涫��������(Deposit box)��\n");
         set("value", 1000);
     }
}
int is_container() { return 1; }

void init ()
{
    add_action("do_mark","mark");
}

int do_mark(string arg)
{
    object who=this_player();
    object me=this_object();
    if (!arg) return notify_fail("�����������ϱ��ʲô?\n");
    if (stringp(me->query("mark"))) 
      tell_object(who,"�㽫������ԭ�еı�ǲ�ȥ��\n");
    me->set("mark",arg);
    tell_object(who,"���ں����Ͽ��ϡ�"+arg+"����������\n");
    me->set("long","һ������,������š�"+arg+"����������\n");
    return 1;
}    
