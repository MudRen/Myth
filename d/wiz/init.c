// Room: /d/wiz/init.c
// mon 3/18/99
#include <ansi.h>
inherit ROOM;

void show_gift(object me);
string _show_gift(object me);
void do_finish(object me);
void get_start(object me);
void get_start0(object me);

string start_room="/d/city/kezhan";
string *index=({
        "str","con","int","spi",
        "cps","per","cor","kar",
        });
mapping giftn=([
        "str":"���",
        "con":"����",
        "int":"����",
        "spi":"����",
        "cps":"����",
        "per":"��ò",
        "kar":"��Ե",
        "cor":"��ʶ",
        ]);
mapping gift=([
        "str":20,
        "con":20,
        "int":25,
        "spi":25,
        "cps":20,
        "per":20,
        "kar":20,
        "cor":20,
        ]);

void create()
{
        set("short", "��ӭ���������񻰣�\n");
        set("no_fight",1);
        set("no_magic",1);
        set("no_net_dead",1);
  set("exits", ([ 
  "down" : "/d/city/kezhan",
]));
        
        setup();
}

void init()
{
    object me=this_player();
    
    if(!userp(me)) return;
    if(!wizardp(me) &&
            ((int)me->query("combat_exp")>0 ||
             (int)me->query("daoxing")>0 ||
             (int)me->query("no_gift")==0 )) {
        me->move(start_room);
        return;
    }  
    add_action("do_block","",1);
    add_action("get_start1","start");
    if(me->query("no_gift")) {
      me->set_temp("gifts",copy(gift));
      me->set_temp("gift_left",0);
      call_out("get_start0",0,me);
    }
}

void get_start0(object me)
{
    if(!me) return;
    
    me->command("start");
}

int get_start1(string arg)
{
    object me=this_player();
    write("\n\n��ӭ���������񻰣�\n");
    write(@LONG

�ڿ�ʼ�������������֮ǰ������ҪΪ�Լ������������ѡ��һ��
���ʵ��츳����Ϊ�⽫������ķ�չ���ش��Ӱ�졣�������е�
�����츳���������� help gifts ����ÿ����һ��ʮ����ʮ֮
�����������ʾ��һ����ֵԽ��Խ�ã���������ܺ��ǹ̶�����ġ�
LONG
        );
    get_start(me);
    return 1;
}

void get_start(object me)
{
    if(!me) return;
    show_gift(me);
    input_to("get_input",me);
}

void get_input(string arg, object me)
{
    int ind;

    if(!me) return;
    if(!arg || sscanf(arg,"%d",ind)!=1 || ind<0
            || (ind>3 && ind!=9)) {
        get_start(me);
        return;
    }
    if(ind<8) {
        write("������"+giftn[index[ind]]+"����ȡֵ[10-30]��");
        input_to("get_number",me,ind);
        return;
    } else {
        write("��ȷ�����ܵ�ǰ���츳������[y/n]");
        input_to("get_finish",me);
        return;
    }
}

void get_finish(string arg, object me)
{
    if(!me) return;
    if(!arg) {
        write("��ȷ�����ܵ�ǰ���츳������[y/n]");
        input_to("get_finish",me);
        return;
    }
    if(arg[0..0]=="y" || arg[0..0]=="Y") {
        do_finish(me);
        return;
    }
    if(arg[0..0]=="n" || arg[0..0]=="N") {
        get_start(me);
        return;
    }
    write("��ȷ�����ܵ�ǰ���츳������[y/n]");
    input_to("get_finish",me);
    return;
}

void show_gift(object me)
{
    write(_show_gift(me));
}

string _show_gift(object me)
{
    mapping my;
    string result;
    int left;

    if(!me) return "";
    my=me->query_temp("gifts");
    left=me->query_temp("gift_left");
    if(!my) return "";
    
    result=("\n");
    result+="��������������������������������������������������\n";
    result+=sprintf(
//          " 0. ������[%d]        1. ��ò��[%d]\n"+
//            " 2. ��ʶ��[%d]        3. ��Ե��[%d]\n"
//          +" 4. ���[%d]        5. ���ǣ�[%d]\n"+
//           " 6. ���ԣ�[%d]        7. ���ԣ�[%d]\n"
            " 0. ���[%d]        1. ���ǣ�[%d]\n"+
            " 2. ���ԣ�[%d]        3. ���ԣ�[%d]\n"
             ,
//          my["cps"],my["per"],my["cor"],my["kar"],
            my["str"],my["con"],my["int"],my["spi"]
            );
    result+="��������������������������������������������������\n";
    if(left)
      result+="������"+chinese_number(left)+"���츳��û�з��䡣\n";
    result+="��ѡ����������������һ���츳��ȡֵ[0-3]��\n"+
        "ѡ��[9]����ܵ�ǰ�����ã�";
    return result;
}

void do_finish(object me)
{
    mapping gt;
    int i, left, ok;
    string *key;
    object env;
    
    if(!me) return;
    left=me->query_temp("gift_left");
    if(left>0) {
        write("���ܹ����� 90 ���츳�����ڻ���ʣ��"+chinese_number(left)
            +"���츳û�з��䡣\n");
        write("���Ƿ������������Щʣ�������[y/n]");
        input_to("continue_finish",me);    
        get_start(me);
        return;
    } else if(left<0) {
        write("Sth wrong, let wiz know.\n");
        return;
    }   

    gt=me->query_temp("gifts");
    if(!gt || !mapp(gt)) {
        write("Something wrong.\n");
        return;
    }
    if((int)(gt["str"]+gt["con"]+gt["int"]+gt["spi"])>90) {
        write("���"+giftn["str"]+"��"+
                giftn["con"]+"��"+
                giftn["int"]+"��"+
                giftn["spi"]+"֮�Ͳ��ܶ��� 90 ��\n");
        get_start(me);
        return;
    }

    /*
    if((int)(gt["cps"]+gt["per"]+gt["kar"]+gt["cor"])>80) {
        write("���"+giftn["cps"]+"��"+
                giftn["per"]+"��"+
                giftn["kar"]+"��"+
                giftn["cor"]+"֮�Ͳ��ܶ��� 80 ��\n");
        get_start(me);
        return;
    }
    */
    
    ok=0;
    while(!ok) {
        gt["cps"]=10+random(21);
        if(me->query("gender")=="����")
          gt["per"]=10+random(21);
        else
          gt["per"]=15+random(16);  
        gt["kar"]=10+random(21);
        gt["cor"]=80-gt["cps"]-gt["per"]-gt["kar"];
        if(gt["cor"]>=10 && gt["cor"]<=30) ok=1;
    }
    
    key=keys(giftn);
    i=sizeof(key);
    while(i--) {
        if(undefinedp(gt[key[i]])) {
            write("Sth wrong, tell wizard.\n");
            return;
        }
        me->set(key[i],gt[key[i]]);
    }
    me->delete("no_gift");
    me->flush_buffer(); // clear receive message buffer.
    //add by mudring@sjsh
    me->set("env/prompt", "time");
    me->set("env/wimpy", 60);
    tell_object(me,"\n\n\n�ã�Ը���������������죡\n\n\n");
    tell_object(me,
        "ֻ����ǰϼ��һ�������Ѿ�������һ��İ�������磨����룩������\n\n");

    if (("/adm/daemons/band"
       ->create_char_banned(query_ip_number(me)) == 1 ||
       "/adm/daemons/band"->is_banned(query_ip_number(me)) == 1) 
            && !wizardp(me)) {
            me->move("/d/wiz/guest");
            log_file( "ALLCONT", sprintf("from banned site\n"));
            return;
    }
    env=load_object(start_room);
    tell_object(env,({"\n������ƺ�Ȼӿ������ʡ�\n\n",
                "\n���һ������ٿ�ػ���������\n\n",
                "����Զ�����춯��һ�����죬�漴һ���������������\n"})
            [random(3)]);
    me->move(env,1);
    me->save();
    return;
}
    
void continue_finish(string arg, object me)
{
    if(!me) return;
    if(!arg) {
        write("���Ƿ������������Щʣ�������[y/n]");
        input_to("continue_finish",me);    
        return;
    }
    if(arg[0..0]=="y" || arg[0..0]=="Y") {
        get_start(me);
        return;
    }
    if(arg[0..0]=="n" || arg[0..0]=="N") {
        me->set_temp("gift_left",0);
        do_finish(me);
        return;
    }
        write("���Ƿ������������Щʣ�������[y/n]");
        input_to("continue_finish",me);    
    return;
}
void get_number(string arg, object me, int ind)
{
    mapping gt;
    int value, old_value;
    string name;
    
    if(!me) return;
    if(!arg || sscanf(arg,"%d",value)!=1) {
        write("������"+giftn[index[ind]]+"����ȡֵ[10-30]��");
        input_to("get_number",me,ind);
        return;
    }
    if(value<10 || value>30) {
        write("��ֵӦ���� 10 �� 30 ֮�䡣\n");
        write("������"+giftn[index[ind]]+"����ȡֵ[10-30]��");
        input_to("get_number",me,ind);
        return;
    }
   
    gt=me->query_temp("gifts");
    if(!gt || !mapp(gt)) {
        write("Something wrong.\n");
        return;
    }
    
    name=index[ind];
    old_value=gt[name];
    gt[name]=value;
    
    if((int)(gt["str"]+gt["con"]+gt["int"]+gt["spi"])>90) {
        gt[name]=old_value;
        write("���"+giftn["str"]+"��"+
                giftn["con"]+"��"+
                giftn["int"]+"��"+
                giftn["spi"]+"֮�Ͳ��ܶ��� 90 ��\n");
        write("������"+giftn[index[ind]]+"����ȡֵ[10-30]��");
        input_to("get_number",me,ind);
        return;
    }
/*
    if((int)(gt["cps"]+gt["per"]+gt["kar"]+gt["cor"])>80) {
        gt[name]=old_value;
        write("���"+giftn["cps"]+"��"+
                giftn["per"]+"��"+
                giftn["kar"]+"��"+
                giftn["cor"]+"֮�Ͳ��ܶ��� 80 ��\n");
        write("������"+giftn[index[ind]]+"����ȡֵ[10-30]��");
        input_to("get_number",me,ind);
        return;
    }
 */   
    me->add_temp("gift_left",old_value-value);
    me->set_temp("gifts",gt);
    write("�㽫"+giftn[name]+"��Ϊ"+chinese_number(value)+"��\n");

    get_start(me);
}


int do_block(string arg)
{
    object me=this_player();
    string verb=query_verb();

    if(!userp(me) || wizardp(me)) return 0;
    if(verb=="look" ||
       verb=="help" ||
       verb=="story" ||
       verb=="say") return 0;
       
    return 1;
}
