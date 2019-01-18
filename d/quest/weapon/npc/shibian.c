// npc: shibian.c
// Jay 3/26/96
// modify by five
#include <ansi.h>
inherit NPC;


void create()
{
        set_name("�̱�", ({ "shibian"}) );
        set("nickname", HIM "��" NOR );
        set("gender", "Ů��" );
        set("age", 20);
        set("long",     
                "��ͷ�ϰ�������ɫɴ��һ������ɫ���ۣ�û��һ˿���塣\n");
        set("str", 25);
        set("per", 20);
        set("kar", 17);
        set("int", 30);
        set("eff_dx", 300000);
        set("nkgain", 200);

        set_skill("unarmed", 140);
        set_skill("dodge", 140);
        set_skill("parry", 140);
        set_skill("spells", 140);  
        set_skill("dao", 140);
        set_skill("literate", 140);
        set_skill("stick", 140);  
        set_skill("qianjun-bang", 140);
        set_skill("puti-zhi", 140);  
        set_skill("jindouyun", 140);
        set_skill("dodge", 140);  
        set_skill("force", 140);   
        set_skill("wuxiangforce", 140);

        map_skill("spells", "dao");
        map_skill("unarmed", "puti-zhi");
        map_skill("force", "wuxiangforce");
        map_skill("stick", "qianjun-bang");
        map_skill("parry", "qianjun-bang");
        map_skill("dodge", "jindouyun");


        set("per", 30);
        set("max_kee", 2000);
        set("max_gin", 2000);
        set("max_sen", 2000);
        set("force", 2500);
        set("max_force", 2500);
        set("force_factor", 100);
        set("mana", 2450);
        set("max_mana", 2500);
        set("mana_factor", 100);
        
        set("inquiry", ([
                "���"  : "ʦ�����Ұ���������ޣ���������Ҳ����һ����Ӱ��˭Ҫ����أ�\n",
                "ԭ��"  : "���ֻ���ú�˿����\n",
        ]) );

        setup();

        carry_object("/d/obj/cloth/pink_cloth")->wear();
}

void init()
{
        ::init();
        add_action("do_zhu","zhu");
}


int accept_object(object who, object ob)
{       
        if(!(who->query_temp("whip") ) ){
                message_vision(HIC"ʦ��û��ͬ��Ϊ����ޣ�����ذɣ�\n"NOR, who);
                remove_call_out("destrory");
                call_out("destrory",1,ob);
                return 1;
        }
        who->delete_temp("whip");
        who->set_temp("m_whip",1);
        switch ((string)ob->query("name") ) 
        {
                case "��˿����": 
                        break;
                default :
                        message("vision","����ʲô��ʦ��˵�ⲻ���������쳤�ޣ�",who);
                        return 0;
        }
        message("vision","�̱޵�ͷ������һ�����е�"+(string)ob->query("name")+
                        "���˵�ͷ˵��\n", who);
        message("vision","���������������ھͿ�ʼ��ޣ�\n", who);
        write("����λ"+RANK_D->query_respect(who)+"���������ְɣ�(zhu �޵����� Ӣ�Ĵ���)\n");
                remove_call_out("destrory");
                call_out("destrory",1,ob);
        return 1;

}

int do_zhu(string arg)
{
        string o_name,id,w_name;
        object whip,make_time;   //���ɵ��������
        object me;
        int i;
        me = this_player();
        if(!(me->query_temp("m_whip")) ) 
                return notify_fail("ʲô?\n");
        me->delete_temp("m_whip");
        me->delete_temp("get_orc");
        me->delete_temp("or");

        if((me->query("weapon/make")) ){
                say("�̱�һ��ãȻ�����Ѿ���һ������������ˣ�������ʲô���ѵ�������ô��\n");
                return 2;
        }
        if( !arg )
                return notify_fail("�̱������˵����ý������Ƽ����ź��ڶ���˵��\n");
        sscanf(arg ,"%s %s" ,w_name ,id);
                if(!w_name||!id)
                return notify_fail("ʲô?(ʹ��zhu �޵����� Ӣ�Ĵ���\n)");
        i = strlen(id);
        while(i--)
                if( id[i]<'a' || id[i]>'z' )
                        return notify_fail("�Բ��𣬱޵�Ӣ�Ĵ���ֻ����Ӣ����ĸ��\n");
        o_name="��˿����";
        make_time=NATURE_D->game_time();
        message_vision(me->name()+"������һ�ᣬ���̱�����˵�˼��仰���̱޵��˵�ͷ��˵���ðɣ�\n",me );
        message_vision("\n�̱޻ع����ó�һ�Ѻ������˵�ذ�ף�������$N�����У��Լ��ó���˿����˵����ʼ�ɣ�\n",me );
        message_vision(HIB "$N˫�ֽ�����סذ�ף��þ�ȫ��������������ȥ��\n" NOR,me);
        message_vision(RED "ֻ�����͵�һ�����죬ذ��һ�����̵���$N�����ϣ�\n" NOR,me );
        message_vision(YEL "$Nֻ�����ֱ����˿�һ�ȣ�������Ѫ�������������ѪҺ�ƺ���������������\n" NOR,me);
        message_vision(HIM "һ��Ѫ�����������������ԴԴ���ϵ����̱����еĺ�˿����ӿȥ\n" NOR,me );
        if( (me->query("kee"))<(me->query("max_kee")) || (me->query("sen"))<(me->query("max_sen")) || (me->query("force"))<(me->query("max_force")) )
        {
                message_vision(HIR "ͻȻ$N������Ѫһ��ӿ��һ�������Ӳ������������� \n" NOR, me);
                me->set("force",0);
                me->unconcious();
                return 1;
        }
        message_vision(HIR "ֻ������һ�����죬һ�����޴�¯��ٿȻԾ�𡣻���һ������͵���$N��ǰ�ش�������\n" NOR,me );
        say("�̱޼�״��У���޳��ɣ���Ѫ�Լ�����������\n");
        message_vision("$Nֻ������ǰһ����һ����ӰѸ���ޱȵĵ�����$N����ǰ��\n",me );   
        message_vision(HIR "����͸�ش������̱޲Һ�һ������Ѫ����$N�������ǣ�\n" NOR,me );
        message_vision(RED "�̱޽���һ�����ȣ������˵��ϡ��̱��Ѿ�����һϢ�ˡ�\n" NOR,me);
        this_object()->set("eff_kee",10);
        message_vision("�����ַ����������ɵ���գ��˵�һ����ص����ϡ�\nһ�ҵľ����������Σ�һ���ֹ��ڳ��š�\n",me );

        me->set("kee",10);
        me->set("sen",10);
        me->set("force",0);

        me->set("weapon/make",1);               //����������ֹ����ı�־              
        me->set("weapon/name",w_name);  //����������
        me->set("weapon/id",id);                //�����Ĵ���
        me->set("weapon/lv",1);         //�����ȼ�
        me->set("weapon/or",o_name);    //��¼����ԭ��
        me->set("weapon/value",0);              //��¼�����������еĵ���        
        me->set("weapon/type","��");
        me->set("weapon/time",make_time);

        whip=new("/d/quest/m_weapon/weapon/m_whip",1);    //�����±�
        whip->move(this_player());
        message_vision("�̱�������ϣ����Ű߰�Ѫ���ĳ��ޣ�˵��\n�ޡ����ѡ����ɡ������̱޵����񡣡���Ҳ������ˡ�������\n",me );
        say("�̱޼��ѵ�˵���ޡ����������պã��Ҹ����ˡ�����\n");
        message_vision("�̱�˵�ꡣٿ�ı㲻���ˡ�\n",me);
        destruct(this_object());
        return 1;
}
void destrory(object ob)
{
        destruct(ob);
}

