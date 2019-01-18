// created by kuku@sjsh  2003.1
// ѡ��ְҵ��npc

inherit NPC;
string apply_occupation(object me);
string *occupation = ({
        "��ʿ",
        "С͵",
        "�̿�",
        "ħ��ʦ",
        "�÷�",
        "����",
        "��ľ��",
        "����",
});
private init_new_player(object me);
int set_attribute(object me,int str, int con, int intt, int per, int cor, int cps, int spi, int kar);

void create()
{
         set_name("������", ({"lao xiansheng", "xiansheng","lao"}));
        set("age", 52);
        set("gender", "����");
         set("int", 35);
        set("long","���������и������ְҵ����������Ҫ��ѡ��һ���Լ�ϲ����ְҵ����û��\n");
         set("title", "ְҵ�ܹ�");
        set("attitude", "friendly");
         set("combat_exp", 40000);
        set("daoxing", 100000);
         set("max_force", 400);
         set("force", 400);
         set("force_factor", 5);
        set_skill("unarmed", 60);
        set_skill("dodge", 60);
        set_skill("parry", 60);
         set_skill("literate", 150);
        set("inquiry", ([ 
                "ְҵ" : (: apply_occupation :),
         ]) );
         setup();
        carry_object("/d/obj/cloth/linen")->wear();
}

void init()
{
         call_out("greeting", 1, this_player());
        ::init();
}

void greeting(object who) 
{
        if( !who || environment(who) != environment() ) return;
        if( who->query("combat_exp") < 200000 && !who->query("occupation")) {
                tell_object(who,"���������ĸ����㣺�����ģ���ѡ��(ask xiansheng about ְҵ)һ��ϲ����ְҵ�ɣ����ڲ���ม�\n");  
        }
}

string apply_occupation(object me)
{
        me=this_player();
        if( me->query("occupation")!= 0 ){
                return "�㲻���Ѿ���ְҵ����\n";
        }
        if( me->query("combat_exp")>200000){
                return "�����ѧ̫���ˣ��Ѿ�������ѡ��ְҵ��\n";
        }
 
        write("Ŀǰ��������������ְҵ�ɹ�ѡ��");
        write("
                ��. ��ʿ
                ��. С͵
                ��. �̿�
                ��. ħ��ʦ
                4 . �÷�
                5 . ���� 
                6 . ��ľ��
                7 . ���� 
        \n");
        write("��ѡ�������������������µ�ְҵ��0��1��2��3��4��5��6��7����");
        input_to("get_nresp",me);
}

private void get_nresp(string arg, object me)
{
        if( arg=="" ) {
                write("��ѡ�������������е�ְҵ��0��1��2��3��4��5��6��7����");
                input_to("get_nresp", me);
                return;
        }
        if( arg[0]=='0' || arg[0]=='1' || arg[0]=='2'|| arg[0]=='3'|| arg[0]=='4' || arg[0]=='5' || arg[0]=='6' || arg[0]=='7'){
                me->set("occupation",occupation[(int) (arg[0]-'0')]);
                init_new_player(me);               
                return;
        }
        else {
                write("�Բ�����ֻ�ܴӣ�0,1,2,3,4,5,6,7����ѡ�� ");
                input_to("get_nresp", me);
                return;
        }
}

private init_new_player(object me)
{
         string occupation;
        occupation = me->query("occupation");
        switch(occupation){
                case "��ʿ":
                        set_attribute(me,30,25,15,15,15,15,15,10);     
                        break;
                case "С͵":
                        set_attribute(me,20,15,12,10,25,10,18,30);
                        break;
                case "�̿�":
                        set_attribute(me,15,25,15,15,30,10,15,15);
                        break;
                case "ħ��ʦ":
                        set_attribute(me,15,15,30,15,10,20,25,10);
                        break;
                case "�÷�":
                        set_attribute(me,15,20,10,30,13,15,25,12);
                        break;
                case "����":
                        set_attribute(me,15,15,30,30,10,15,15,10);
                        break;
                case "��ľ��":
                        set_attribute(me,20,20,10,10,15,25,15,25);
                        break;
                case "����":
                        set_attribute(me,30,20,10,15,10,30,15,10);
                        break;
        }       
        me->save();
        write("��ѡ����"+me->query("occupation")+"��Ϊ�������ְҵ��\n");
        write("�ú÷ܶ��ɣ�����һ��������Ϊ��\n");
}

int set_attribute(object me,int str, int con, int intt, int per, int cor, int cps, int spi, int kar)
{
         me->set("str",str);
         me->set("con",con);
         me->set("int",intt);
         me->set("per",per);
         me->set("cor",cor);
         me->set("cps",cps);
         me->set("spi",spi);
         me->set("kar",kar);
         return 1;
}
