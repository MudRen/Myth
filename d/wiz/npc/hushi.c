//By stey@2001/12/26 �����Ż�

#include <ansi.h>

inherit NPC;

/*
string *msg_d = ({
                      "����","sos","SOS",  });
*/

void create()
{
        set_name("��ʿ", ({"hu shi","hushi"}));
        set("title", HIY"�����ġ�ҽ��ʹ��"NOR);
        set("gender", "Ů��" );
        set("age", 23);
        set("per", 40);
        set("long", HIR"һ�������Ĵ���Ļ�ʿ�����������������������ý�����˼���Ρ�\n"NOR);
        set("combat_exp", 10000000);
        set("attitude", "peaceful");
        set("str", 50);
//   ������set("class","xian");
        set_skill("literate", 800);
        set("max_kee", 1000);
        set("max_sen", 1000);
        set("max_force", 1000);
        
        set("no_clean_up",1);
        setup();
/*
//���������Ҫ���ӵ�Ƶ��
        if( !clonep() ) CHANNEL_D->register_relay_channel("rumor");
//        if( !clonep() ) CHANNEL_D->register_relay_channel("chat");
        if( !clonep() ) CHANNEL_D->register_relay_channel("party");
       if( !clonep() ) CHANNEL_D->register_relay_channel("es");
       if( !clonep() ) CHANNEL_D->register_relay_channel("sldh");
       if( !clonep() ) CHANNEL_D->register_relay_channel("new");
*/
        
}

/*
void relay_channel(object criminal, string channel, string msg)
{

        int i;
        string criname,result;
        int howlong;
        if( !userp(criminal) ) return;

        for(i=0; i<sizeof(msg_d); i++)
        {
            if( strsrch(msg, msg_d[i]) >= 0)
                   {
                    message_vision(CYN"�Ȼ������֣����������󺺣�һ�¾Ͱ�$Ņ�����ӡ�\n$Nֻ�����ε����ţ���������\n"NOR, criminal);
                    
                    criname = criminal->query("name") + "("+criminal->query("id")+")";
                    howlong=15;//��������Զ��Ȼ�ʱ��,15=15����
                    
                    result = sprintf("%s��%sƵ������(%s)�Ȼ�����������ҽ�� %d ��\n",
                    criname,channel,msg,howlong);
                    
                    criminal->set("jijiu/howlong",howlong);
                    criminal->set("jijiu/temp",result);
                    criminal->move("/d/wiz/jijiu");
                 
                    message("channel:rumor",HIM"����Ѩ���硿ĳ�ˣ���˵ "HIR+criname+HIM" �ں��м��ȣ����Ȼ�����ȥ����ʿ�ˡ�\n"NOR, users());
                    return;
                    }
        }
}

*/
