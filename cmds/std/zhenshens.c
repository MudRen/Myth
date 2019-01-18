// saiya.c stey 2001/12/30

#include <ansi.h>

int do_bian(object me);

int main(object me, string arg)
{
    string id;
    object obj,newob,*inv;
    int mana,spells,dmana,level,i;
    string str;

    seteuid(getuid());

    if( me->is_fighting() )
        return notify_fail("������ս������Ͼ����\n");
    if( me->is_busy() || me->query_temp("pending/exercising"))
        return notify_fail("����æ���أ�û�������\n");

    if (!arg && arg!="changedown" && arg!="changeup")
        return notify_fail("\n�����ʹ��zhenshens changedown(���)����zhenshens changeup(����)��\n");



    if (arg=="changeup"){
        spells=me->query_skill("spells");
        mana=me->query("mana");
        level=me->query("level");
        if(me->query_temp("getdd/zhenshens")) return notify_fail("���Ѿ��ǽ�ջ��岻��֮���ˡ�\n");
        if (spells<25)
            return notify_fail("��ķ���������\n");

        if (mana<150)
            return notify_fail("��Ŀǰ����������ӯ��\n");
        if (level<50)
            return notify_fail("��ĵȼ�������\n");

        if (me->query_temp("zhenshens_time") && me->query_temp("zhenshens_time")+60 > time())
            return notify_fail("��������Ϣ����,�ȵȰɡ�\n");



        inv = all_inventory(me);
        for(i=0; i<sizeof(inv); i++)  {
            if( inv[i]->query("zhanyisjsh")) {
                message_vision("ͻȻ�䣬$n��һ���׹��ȥ����Ӱ���٣�\n",me,inv[i]);
                destruct(inv[i]);
            }
        }
        if( !me->query("s_fayi") || !(newob=find_object(me->query("s_fayi"))))
            {
            newob = new("/obj/zhenshencloth");
            newob->set("owner_id", me->query("id"));
            newob->set("armor_prop/armor",level+65);
            newob->set("level",level+10);
            newob->set("armor_prop/spells", level/4);
            newob->set("zhanyisjsh", 1);
            }
        newob->move(this_player());
        newob->wear(me);
        me->set("s_fayi",file_name(newob));
        me->add_temp("apply/attack", level/4);
        me->add_temp("apply/damage",level/4);
        message_vision(HIY "$N����������ϯ�ض����������������ͷ��һ������ƮȻ����������\n"
          +"\nֻ��$Nȫ�����������죬��ʱ���������ɢ��������������$Nȫ������������\n"
          +"\n$N��ʱ����Ϊ֮һ����ʱ����������ƺ����ĵ������Σ�����������\n\n" NOR,me);
        message("channel:rumor",HIG+"��"HIW"���紫˵"HIG"��"HIC"���շ�"HIW"����˵"+me->query("name")+"�ƺ쳾��ȥ����������飬�޳ɲ���֮�壬���õ�ʥ�鷨�¡�\n"+NOR,users());
        str=HIY"��������"NOR+me->query("title");
        if (me->query("gender")=="Ů��") str+="Ů";
 
        me->set_temp("zhenshens_time",time());
        me->delete_temp("zhenshendown");
        me->set_temp("getdd/zhenshens",1);
    }

    if(arg=="changedown") {
        if (!me->query_temp("getdd/zhenshens"))
            return notify_fail("��û�õ�����֮����ô�ָܻ�ԭ״����\n");

        if (me->query_temp("zhenshendown"))
            return notify_fail("���Ѿ��ָ�ԭ״�ˡ�\n");
       
        me->set_temp("apply/attack",(me->query_temp("aplpy/atyack")-(level/4)));
        me->set_temp("apply/damage",(me->query_temp("aplpy/damage")-(level/4)));
       
        me->delete_temp("apply/short");
        me->delete_temp("apply/long");
        me->delete_temp("apply/name");
        me->set_temp("zhenshendown",1);
        if( newob=find_object(me->query("s_fayi")))
            {
            if (newob->query("equipped"))  newob->unequip();
            destruct(newob);
            }
        inv = all_inventory(me);
        for(i=0; i<sizeof(inv); i++)  {
        
            if( inv[i]->query("id") =="shengling fayi") {
                message_vision(HIW"\n���С�������Ļ�������ҷ��ڣ��ն��ȷ��£�ʾ�ͽ䡣\n"NOR,me,inv[i]);
                if (inv[i]->query("equipped"))  inv[i]->unequip();
                destruct(inv[i]);
            }
        }
        me->delete_temp("getdd/zhenshens");
        message_vision(HIY "\n$N�ܵ���˾��ţ�������ң���������Żָ�ԭ״��\n" NOR,me);
        return 1;
    }
    return 1;
}



int help(object me)
{
    write(@HELP

ָ���ʽ �� Zhenshens changeup (����������������)
            Zhenshen changedown (�Ƽ���������̬)
���ָ��:     Quit
�ƺ쳾��ȥ�������������Ҫȡ��������ķ�����Ϊ������ƽʱ���۵ĵ������С�



HELP
    );
    return 1;
}


