inherit ITEM;
string *b_names = ({
        "����",
        "�����",
        "ţ��",
        "�˲�",
});
mapping names = ([
  "����":       "san qi",
  "�����":       "gouji zi",
  "ţ��":       "niu huang",
  "�˲�":       "ren shen",
]);
void setname() 
{
int i;
string name,*kn,*id;
i=random(4); 
name=b_names[i];
set("yaocai",b_names[i]); 
id=({names[b_names[i]],"yaocai"});
 set_name(name,id);  
}
void create(int i) 
{
setname();
        if( clonep() )
                set_default_object(__FILE__);
        else {
                  set("long", "��ҩ�Ĳ��ϡ�\n");
                set("unit", "��");
                set("value", 11111);
        }
        setup();
}
