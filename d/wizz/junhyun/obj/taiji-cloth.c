//������ʦ��
//by junhyun
#include <armor.h>
#include <ansi.h>

inherit CLOTH;

string setcolor();

void create()
{
        set_name(HIW"������ʦ��"NOR, ({ "longhu tianshipao" ,"cloth", "tianshipao", "pao" }));
        set_weight(3000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("text" , "�����й����̴�ʼ���ŵ���ĵ��ۣ��������±�̫����������Χ��
�ƺ����˴��������Ĺ�Ч���������������ʦ����ע��̫��(tianji)����\n"NOR);
                set("long",HIW+query("text") );
                set("material", "silk");
                set("unit", "��");
                set("unique", 1);
                set("value", 10000000);
                set("treasure", 1);
                set("wear_msg", HIW"ֻ��$N"HIW"˫��һ�������һ������͸����ɫ��ʵ���ʦ�۴��������ϡ�\n" NOR);
                set("armor_prop/armor", 180);

                set("owner","no owner");
        }
        setup();
}

void init()
{
        add_action("do_taiji","taiji");
}

int do_taiji(string arg)
{
        int cost;
        object me = this_player();

        if( query("force") >= 13990 )
                return notify_fail("��ʦ�����Ѿ�������̫������������Ҳ�޷�ע���ˣ�\n");

        if( me->query_skill("force") < 160 )
                return notify_fail("����ڹ��ȼ��������޷�ע��������\n");

        if( me->query_skill("yinyun-ziqi",1)>100 && me->query_skill_mapped("force")=="yinyun-ziqi" )
                cost = 1000;
        else
                cost = 1200;

        if( cost > me->query("force") )
                return notify_fail("����������㣬�޷�ע���㹻��������\n");

        if( query("owner")!=me->query("id") && query("owner")!="no owner" ) {
                set("force" , query("force")/2);
                message_vision(MAG"$N�����Լ�����������ʦ����ԭ�е��������ͻ����Ȼ���ջ���ע����������������Ѿ���ʧ�˲��١�\n",me);
        }
        set("owner" , me->query("id"));

        add("force" ,  1000);
        if (query("force") > 13990) set("force" , 13990);
        me->add("force" , -cost);

        if( cost<=1000 )
                message_vision(MAG"$N"MAG"���Ϸ���һ��������������˫���鰴������ʦ�ۣ���̫������ע����ʦ��֮�С�\n"NOR,me);
        else
                message_vision(HIC"$N"HIC"Ǳ���ڹ���Ŭ��������ע��������ʦ�ۣ������Ȼ�ɹ�����Ϊ����̫���������໨�˵�������\n"NOR,me);
        
        setcolor();

        return 1;
}

mixed ob_hit(object target, object me, int damage)
{
        int times , kee , cost , charge = 16;
        string color;
        
        if(query("force")<= 0 || damage<250)
                return 0;

        if(query("owner") == me->query("id"))
                times = 10;
        else 
                times = 15;

        cost = (damage / 2)*charge/10*times/10;
        kee = damage/2;
        if( cost > query("force") ) {
                kee = kee * query("force") / cost ;
                cost = query("force");
        }               
        add("force" , -cost);

        if(wizardp(me) && me->query("env/test")) 
                tell_object(me,sprintf("kee:%d , force:%d   ",kee,cost));

        color = setcolor();     
        if( times<=10 )
                message_vision(query("name")+color+"ͻȻ����ҫ�۵Ĺ�â���ֵ���$N"+color+"�Ĳ��ֹ��ƣ�\n"NOR,target);
        else
                message_vision(query("name")+color+"ͻȻ����ҫ�۵Ĺ�â���ֵ���$N"+color+
                                        "�Ĳ��ֹ��ƣ�����Ϊ�ڹ���ͻ���˷��˲��ٴ����������\n"NOR,target);

        return -kee;
}

string setcolor()
{
        int lvl;
        string color , s;

        if ( query("force") != 0 )
                lvl = query("force") / 1000;
        else
                lvl = 0;
        switch (lvl)  {
                case  0:
                case  1:
                case  2: color = HIW;break;
                case  3:
                case  4: color = HIC;break;
                case  5:
                case  6: color = CYN;break;
                case  7:
                case  8: color = HIB;break;
                case  9:
                case 10: color = BLU;break;
                case 11:
                case 12: color = HIM;break;
                case 13: color = MAG;break;
                default: color = HIW;
        }
        set("name" , color+"������ʦ��"NOR );
        
        if( lvl > 0 )
                s = color+"��ʦ��֮���Ѿ�ע��"+CHINESE_D->chinese_number(lvl)+"��̫��������\n"NOR;
        else
                s = "";
        set("long" , color+query("text")+s);

        return color;
}

