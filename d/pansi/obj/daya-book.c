// daya-jian_book.c

//lestat
#include <ansi.h>
inherit ITEM;

void destroy();
void init();
void init()
{
  if (!wizardp(this_player())) {
    set("no_get","������һ��"+this_object()->query("name")+"��ָ�们��,ƬƬ��ȥ��\n");
    set("no_give","ð����Σ�յ����Ķ��������������ˣ�\n");
    set("no_drop","��ô������飬���˶��ϧѽ��\n");
    set("no_sell","��������֪��"+this_object()->query("name")+"�ļ�ֵ�������Լ����Űɡ�\n");
  }                                    
    call_out("destroy", 120);
}
void create()
{
        set_name(HIY"���ŹŽ���"NOR, ({ "daya_sword_book", "book" }));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
                        "һ�ű�����˿��,������Щ�����,�����������鲼��ӬͷС��,�������������:���ŹŽ��ס�\n"
                        "��������ʱ�������\n");
                set("value", 0);
                set("material", "paper");
                set("skill", ([
                        "name":        "daya-jian",          // name of the skill
                        "exp_required": 1000000,                          // minimum combat experience required
                                                                        // to learn this skill.
                        "sen_cost":     30,                             // gin cost every time study this
                        "difficulty":   30,                             // the base int to learn this skill
                                                                        // modify is gin_cost's (difficulty - int)*5%
                        "max_skill":    100,                            // the maximum level you can learn
                        "min_skill":    0                               // the maximum level you can learn
                                                                        // from this object.
                ]) );
        }
}
//int query_autoload() { return 1; }
void destroy()
{
  destruct(this_object());
}


